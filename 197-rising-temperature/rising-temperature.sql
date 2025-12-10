# Write your MySQL query statement below
select Id from Weather w1 where w1.temperature>(select temperature from weather w2 where w2.recordDate=w1.recordDate - INTERVAL 1 DAY);