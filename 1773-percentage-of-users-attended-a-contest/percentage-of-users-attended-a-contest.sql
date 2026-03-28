# Write your MySQL query statement below

-- select a.user_id,a.user_name,b.contest_id
-- from Users as  a
-- right join Register as b
-- on a.user_id = b.user_id;

-- select a.contest_id,b.user_id,b.user_name
-- from Register as a
-- left join Users as b
-- on a.user_id = b.user_id;


select  distinct a.contest_id
        , round(count(b.user_id) *100.0 / (select count(*) from Users) , 2) as percentage
from Register as a
left join Users as b
on a.user_id = b.user_id
group by a.contest_id
order by  percentage desc, a.contest_id asc; 
