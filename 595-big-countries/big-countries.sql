# Write your MySQL query statement below

select a.name, a.population, a.area
from World as a
where a.area >= 3000000 or a.population >=25000000