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

-- select m.employee_id,
--         m.name,
--         count(e.reports_to) as reports_count,
--         round(avg(e.age)) as average_age
-- from Employees as e
-- join Employees as m
-- on e.reports_to = m.employee_id
--         group by e.reports_to
--         order by m.employee_id

-- 2 nd way to solve this bp 

-- select distinct
--     m.employee_id,
--     m.name,
--     count(e.employee_id) over(partition by e.reports_to) as reports_count,
--     round(avg(e.age)) over (partition by e.reports_to) as average_age
-- from Employees as e
-- join Employees as m
--   on e.reports_to = m.employee_id
--   order by m.employee_id;

  SELECT DISTINCT
    m.employee_id,
    m.name,
    COUNT(e.employee_id) OVER (PARTITION BY e.reports_to) AS reports_count,
    ROUND(AVG(e.age) OVER (PARTITION BY e.reports_to)) AS average_age
FROM Employees AS e
JOIN Employees AS m
  ON e.reports_to = m.employee_id
ORDER BY m.employee_id;

