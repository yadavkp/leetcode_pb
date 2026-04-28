# Write your MySQL query statement below

-- select distinct author_id as id
-- from Views
-- where author_id = viewer_id
-- order by author_id asc;


select distinct v2.viewer_id as id
from Views as v1
join Views as v2
on v1.viewer_id = v2.viewer_id
where v1.author_id = v2.viewer_id
order by id asc;


-- select v1.article_id,v1.viewer_id,v2.author_id
-- from Views as v1
--  join Views as v2
-- on v1.article_id = v2.viewer_id;