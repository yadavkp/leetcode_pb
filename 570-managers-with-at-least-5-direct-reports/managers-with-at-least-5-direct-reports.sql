# Write your MySQL query statement below
-- select a.name , count(a.managerId)
-- from Employee as a
-- left join Employee as b
-- on a.id = b.id
-- where a.id = b.managerId
-- group by a.managerId;


-- select a.name , count(a.managerId)
-- from Employee as a
--   (select )

  with temp as (
    select managerId, count(managerId) as count from  Employee where managerId is not null
    group by managerId
  )
  select name from Employee as a
  left join temp as b
  on a.id  = b.managerId
  where b.count >= 5;
  
