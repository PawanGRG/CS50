-- Write a SQL query to list the titles of all movies released in 2008.
SELECT title FROM movies WHERE year = 2008;

-- Write a SQL query to determine the birth year of Emma Stone.
SELECT birth FROM people WHERE name='Emma Stone';

-- Write a SQL query to list the titles of all movies with a release date on or after 2018, in alphabetical order.
SELECT title FROM movies WHERE year >= 2018 ORDER BY title ASC;

-- Write a SQL query to determine the number of movies with an IMDb rating of 10.0.
SELECT COUNT(*) FROM ratings WHERE rating = 10.0;

-- Write a SQL query to list the titles and release years of all Harry Potter movies, in chronological order.
SELECT title,year FROM movies WHERE title LIKE 'Harry Potter%' ORDER BY year;

-- Write a SQL query to determine the average rating of all movies released in 2012.
SELECT AVG(ratings.rating) AS average_rating
FROM movies
JOIN ratings ON movies.id = ratings.movie_id
WHERE movies.year = 2012;


-- write a SQL query to list all movies released in 2010 and their ratings, in descending order by rating. For movies with the same rating, order them alphabetically by title.
SELECT movies.title , ratings.rating
FROM movies JOIN ratings
ON movies.id = ratings.movie_id
WHERE movies.year = 2010
ORDER BY ratings.rating DESC, movies.title ASC;

-- Write a SQL query to list the names of all people who starred in Toy Story.
SELECT name 
FROM people 
JOIN stars 
ON people.id = stars.person_id 
JOIN movies 
ON stars.movie_id = movies.id 
WHERE title = 'Toy Story';

-- Write a SQL query to list the names of all people who starred in a movie released in 2004, ordered by birth year.
SELECT DISTINCT name FROM people
JOIN stars
ON people.id = stars.person_id
JOIN movies
ON stars.movie_id = movies.id
WHERE movies.year = 2004
ORDER BY people.birth ASC;

-- Write a SQL query to list the names of all people who have directed a movie that received a rating of at least 9.0.
SELECT DISTINCT name FROM people
JOIN directors
ON people.id = directors.person_id
JOIN movies
ON directors.movie_id = movies.id
JOIN ratings
ON movies.id = ratings.movie_id
WHERE ratings.rating >= 9.0;

-- Write a SQL query to list the titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated.
SELECT movies.title FROM movies
JOIN stars
ON movies.id = stars.movie_id
JOIN people
ON stars.person_id = people.id
JOIN ratings
ON movies.id = ratings.movie_id
WHERE people.name = 'Chadwick Boseman'
ORDER BY ratings.rating DESC
LIMIT 5;

-- Write a SQL query to list the titles of all movies in which both Bradley Cooper and Jennifer Lawrence starred.
SELECT movies.title
FROM movies
JOIN stars AS stars_cooper ON movies.id = stars_cooper.movie_id
JOIN people AS people_cooper ON stars_cooper.person_id = people_cooper.id
JOIN stars AS stars_lawrence ON movies.id = stars_lawrence.movie_id
JOIN people AS people_lawrence ON stars_lawrence.person_id = people_lawrence.id
WHERE people_cooper.name = 'Bradley Cooper' AND people_lawrence.name = 'Jennifer Lawrence';

-- Write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.
SELECT DISTINCT p2.name
FROM people AS p1
JOIN stars AS s1 ON p1.id = s1.person_id
JOIN stars AS s2 ON s1.movie_id = s2.movie_id
JOIN people AS p2 ON s2.person_id = p2.id
WHERE p1.name = 'Kevin Bacon' AND p1.birth = 1958 AND p2.name != 'Kevin Bacon';


