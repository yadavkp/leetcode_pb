# Write your MySQL query statement below


-- select class 
-- from Courses 
-- group by class
-- having count(*) > 4 ;


select class
from (
    select class , count(class) as cnt
    from courses
    group by class
) as temp
where cnt >= 5;