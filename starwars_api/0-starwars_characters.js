#!/usr/bin/node
/**
 * Script qui affiche tous les personnages d'un film Star Wars
 * Le premier argument est l'ID du film
 */

const request = require('request');
const filmId = process.argv[2];

if (!filmId) {
  console.error('Veuillez fournir un ID de film');
  process.exit(1);
}

const filmUrl = `https://swapi-api.hbtn.io/api/films/${filmId}`;

// Fonction pour obtenir les détails d'un personnage à partir de son URL
function getCharacterName (characterUrl) {
  return new Promise((resolve, reject) => {
    request(characterUrl, (error, response, body) => {
      if (error || response.statusCode !== 200) {
        reject(error || new Error(`Status Code: ${response.statusCode}`));
        return;
      }
      const character = JSON.parse(body);
      resolve(character.name);
    });
  });
}

// Obtenir les informations du film
request(filmUrl, async (error, response, body) => {
  if (error || response.statusCode !== 200) {
    console.error(error || `Status Code: ${response.statusCode}`);
    process.exit(1);
  }

  const film = JSON.parse(body);
  const characterUrls = film.characters;

  try {
    // Utiliser Promise.all pour maintenir l'ordre des personnages
    const characterNames = await Promise.all(
      characterUrls.map(url => getCharacterName(url))
    );

    // Afficher chaque nom de personnage
    characterNames.forEach(name => console.log(name));
  } catch (err) {
    console.error('Erreur lors de la récupération des personnages:', err);
    process.exit(1);
  }
});
