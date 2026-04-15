# Write your MySQL query statement below

-- select  teacher_id, count( distinct subject_id) as cnt
-- from Teacher 
-- group by teacher_id;

--  solved by the this window function ->>>>


with temp as (
    select distinct teacher_id,subject_id
    from Teacher 
) select teacher_id,count(subject_id)as cnt
from temp
group by teacher_id;