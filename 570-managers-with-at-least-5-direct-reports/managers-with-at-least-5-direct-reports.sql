-- this by the cte , 

  with temp as (
    select managerId, count(managerId) as cnt from  Employee where managerId is not null
    group by managerId
  )
  select name from Employee as a
  left join temp as b
  on a.id  = b.managerId
  where b.cnt >= 5;


  
-- now will solve by inline query

-- solve by the window function ->



-- SELECT DISTINCT name
-- FROM (
--     SELECT a.name,
--            COUNT(e.id) OVER(PARTITION BY a.id) as cnt
--     FROM Employee a
--     INNER JOIN Employee e ON a.id = e.managerId
-- ) t
-- WHERE cnt >= 5;
