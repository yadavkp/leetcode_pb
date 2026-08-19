# Write your MySQL query statement below

-- select distinct author_id as id
-- from Views
-- where author_id = viewer_id
-- order by author_id asc;



select distinct v2.viewer_id as id
from Views as v1
join Views as v2
on v1.viewer_id = v2.viewer_id
and v1.author_id = v2.viewer_id
order by id asc;

