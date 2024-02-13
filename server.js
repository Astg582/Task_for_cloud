const express = require('express');
const path = require('path');
const app = express();

//app.set('view engine', 'ejs');
app.set('views', path.join(__dirname, 'ejs-views'));

const PORT = 3000;

const createPath = (page) => path.resolve(__dirname, 'ejs-views', `${page}.ejs`);
//const createPath = (page) => path.resolve(__dirname, 'views', `${page}.html`);


app.listen(PORT, (error) => {
  error ? console.log(error) : console.log(`Listening port ${PORT}`);
});

app.use((req, res, next) => {
	console.log(`path: ${req.path}`);
	console.log(`method: ${req.method}`);
	next();
});

app.get('/',(req, res) => {
	res.render(createPath('index'));
});

app.get('/',(req, res) => {
	res.render(createPath('index'));
});

app.get('/Contacts',(req, res) => {
	res.render(createPath('contacts'));
});

app.get('/about-us',(req, res) => {
	res.render(createPath('contacts'));
});

app.get('/posts/:id',(req, res) => {
	res.render(createPath('post'));
});

app.get('/post',(req, res) => {
	res.render(createPath('post'));
});

app.get('/add-post',(req, res) => {
	res.render(createPath('add-post'));
});




app.use((req, res) => {
	res
	.status(404)
	.render(createPath('error'));
});


