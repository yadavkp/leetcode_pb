# Write your MySQL query statement below
-- when colm name in the table same as any sql keyword- > then quotes that it simple
--  ex = "rank"

-- select round(score,2) as score,
--     dense_rank() over (order by score desc) as ran
-- from Scores;


WITH Rounded AS (
    SELECT ROUND(score, 2) AS rounded_score
    FROM Scores
)
SELECT 
    rounded_score as score,
    DENSE_RANK() OVER (ORDER BY rounded_score DESC) AS "rank"
FROM Rounded;
