# Write your MySQL query statement below

-- 
-- with cte as (

-- );


-- select distinct l1.num as ConsecutiveNums
-- from Logs l1, Logs l2, Logs l3
-- where l1.id = l2.id-1 and l2.id = l3.id-1
--  and l1.num = l2.num and l2.num = l3.num;

-- v can also compare and by subtacting 1 in the second colm


-- select distinct l1.num as ConsecutiveNums
--  from Logs l1
--  join Logs  l2 on l1.id = l2.id-1
--  join Logs l3 on l2.id = l3.id-1
--  where l1.num = l2.num and l2.num = l3.num;



-- v can also add in first colm and then compare 

 select distinct l1.num as ConsecutiveNums
 from Logs l1
 join Logs  l2 on l1.id+1 = l2.id
 join Logs l3 on l2.id + 1 = l3.id
 where l1.num = l2.num and l2.num = l3.num;

