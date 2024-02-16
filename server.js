const express = require('express');
const ejs = require('ejs');
const path = require('path');
const fs = require('fs');
const multer = require('multer');
const methodOverride = require('method-override');

const app = express();
const port = 3000;

app.set('view engine', 'ejs');

app.use(methodOverride('_method'));
app.use(express.static(path.join(__dirname, 'public')));

const storage = multer.diskStorage({
  destination: './public/post',
  filename: function (req, file, cb) {
    cb(null, file.fieldname + '-' + Date.now() + path.extname(file.originalname));
  }
});

const upload = multer({ storage: storage });

app.get('/', (req, res) => {
 
  fs.readdir('./public/post', (err, files) => {
    if (err) {
      return res.status(500).send('Ошибка чтения папки с файлами.');
    }

    res.render('index', { files });
  });
});

app.post('/upload', upload.single('file'), (req, res) => {
   res.redirect('/');
});

// file deletion
app.delete('/delete', (req, res) => {
	const fileName = req.query.file;  

 if (!fileName) {
    return res.status(400).send('File name is not.');
  } 

  const filePath = path.join(__dirname, 'public', 'post', fileName);

  
  fs.unlink(filePath, (err) => {
    if (err) {
      return res.status(500).send('Error file delete.');
    }

     res.redirect('/');
  });
});


app.listen(port, () => {
  console.log(`Server is running at http://localhost:${port}`);
});

