# Write your MySQL query statement below

-- select a.name 
-- from Customer as a
-- where a.referee_id != 2 or a.referee_id is null;

-- select name 
-- from Customer 
-- where ifnull(referee_id,0) != 2;

select name 
from Customer 
where coalesce(referee_id,0) != 2;