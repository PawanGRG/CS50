-- -- Write a SQL query to list the names of all songs in the database
SELECT name FROM songs;

-- -- Write a SQL query to list the names of all songs in increasing order of temp
SELECT name FROM songs ORDER BY tempo ASC;

-- -- Write a SQL query to list the names of the top 5 longest songs in descending order of length
SELECT name FROM songs ORDER BY duration_ms DESC LIMIT 5;

-- -- Write a SQL query that lists the names of any songs that have danceability,energy, and valence greater than 0.75
SELECT name FROM songs WHERE danceability > 0.75 AND energy > 0.75 AND valence > 0.75;

-- -- Write a SQL query that returns the average energy of all the songs
SELECT AVG(energy) FROM songs;

-- -- Write a SQL query that lists the names of songs that are by Post Malone
SELECT name FROM songs WHERE artist_id =54;

-- -- Write a SQL query that returns the average energy of songs that are by Drake
SELECT AVG(energy) FROM songs WHERE artist_id = 23;

-- -- Write a SQL query that lists the names of the songs that feature other artsists
SELECT name FROM songs WHERE name LIKE '%feat.%' OR name LIKE '%featuring%';
