# Write your MySQL query statement below

-- select id, movie,description ,rating
-- from Cinema
-- where id%2!= 0 and description != "boring"
-- order by rating desc;

-- with temp as (
--     select id , movie,description,rating
--     from cinema
--     where id%2 != 0 and description != "boring"
-- )
-- select * from temp
-- order by rating desc;


select * from 
    (select id , movie,description,rating
    from cinema
    where id%2 != 0 and description != "boring") t
order by rating desc;