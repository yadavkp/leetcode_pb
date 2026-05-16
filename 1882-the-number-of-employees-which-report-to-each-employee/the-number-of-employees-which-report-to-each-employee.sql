# Write your MySQL query statement below

-- with temp as (
--     select reports_to,count(reports_to) as cnt,avg(age) as average_age
--     from Employees
--     group by reports_to
-- )
-- select ;
-- from temp as a
-- inner join Employees as b
-- on 

select m.employee_id,
        m.name,
        count(e.reports_to) as reports_count,
        round(avg(e.age)) as average_age
from Employees as e
join Employees as m
on e.reports_to = m.employee_id
        group by e.reports_to
        order by m.employee_id