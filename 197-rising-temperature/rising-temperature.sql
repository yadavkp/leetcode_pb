# Write your MySQL query statement below

select  a.id
from Weather as a
join Weather as b
   ON DATEDIFF(a.recordDate,b.recordDate) = 1 
where   a.temperature > b.temperature;

    