SELECT result AS results FROM (
  SELECT * FROM (
    SELECT u.name AS result
    FROM users u
    LEFT JOIN MovieRating mr ON u.user_id = mr.user_id
    GROUP BY u.user_id
    ORDER BY COUNT(mr.user_id) DESC, u.name
    LIMIT 1
  ) AS top_user

  UNION ALL

  SELECT * FROM (
    SELECT m.title AS result
    FROM movies m
    LEFT JOIN MovieRating mr ON m.movie_id = mr.movie_id
    WHERE EXTRACT(YEAR_MONTH FROM mr.created_at) = 202002
    GROUP BY m.movie_id
    ORDER BY AVG(mr.rating) DESC, m.title
    LIMIT 1
  ) AS top_movie
) AS combined;
