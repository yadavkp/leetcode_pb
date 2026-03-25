# Write your MySQL query statement below

select a.project_id,
    ROUND(avg(b.experience_years),2) as average_years
from Project as a
left join Employee as b
on a.employee_id = b.employee_id
group by project_id;

-- select a.project_id,a.employee_id,b.name,b.experience_years
--     from Project as a
-- left join Employee as b
-- on a.employee_id = b.employee_id;
