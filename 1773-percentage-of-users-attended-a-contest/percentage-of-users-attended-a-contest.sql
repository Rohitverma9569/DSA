# Write your MySQL query statement below
select r.contest_id ,
Round(count(distinct r.user_id)*100.00/(select count(user_id) from Users),2) as percentage
from Register r
group by r.contest_id
order by percentage desc, r.contest_id asc