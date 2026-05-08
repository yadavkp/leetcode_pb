# Write your MySQL query statement below


select max(num)  as num
from (
    select num, count(*) as cnt
    from MyNumbers 
    group by num
) as temp 
where cnt = 1;