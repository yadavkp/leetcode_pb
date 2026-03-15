# Write your MySQL query statement below

-- using or 

-- select a.name, a.population, a.area
-- from World as a
-- where a.area >= 3000000 or a.population >=25000000


-- using union , this is fast by the or

select name ,population , area
from World
where area >= 3000000

union 

select name ,population , area
from World
where population >= 25000000;

