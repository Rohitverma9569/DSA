# Write your MySQL query statement below
select q.query_name ,ROUND(AVG(q.rating/q.position),2) as quality
,Round((select count(q2.rating) from Queries q2 where q2.rating<3 and q2.query_name=q.query_name)*100/(select count(rating) from Queries q3 where q3.query_name=q.query_name) 
,2) as poor_query_percentage
from Queries q
group by q.query_name 
