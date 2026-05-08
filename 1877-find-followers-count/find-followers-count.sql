# Write your MySQL query statement below

-- select user_id , count( distinct follower_id) as followers_count
-- from Followers 
-- group by user_id
-- order by user_id asc;

--  solve ths pb by the subquery 

select * 
from (
    select user_id, count(distinct follower_id) as followers_count
    from Followers
    group by user_id
    order by user_id desc
) as temp 
order by user_id asc;
