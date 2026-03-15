# Write your MySQL query statement below
select a.name 
from Customer as a
where a.referee_id != 2 or a.referee_id is null;