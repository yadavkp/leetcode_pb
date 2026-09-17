# Write your MySQL query statement below


select 
    e1.employee_id,
    e1.department_id
from Employee as e1
where (
    select count(*)
    from Employee as inner_q
    where inner_q.employee_id = e1.employee_id
) = 1
or e1.primary_flag = "Y";



