#!/usr/bin/node
const request = require('request');
const epNumber = process.argv[2];
const urlPath = 'https://swapi-api.hbtn.io/api/films/' + epNumber;

request(urlPath, function (err, response, body) {
	if (err) throw err;
	const movies = JSON.parse(body);
	const characters = movies.characters;

	characters.forEach((characterUrl) => {
	request(characterUrl, function (err, response, body) {
	  if (err) throw err;
	  const character = JSON.parse(body);
	  console.log(character.name);
	});
  });
});
