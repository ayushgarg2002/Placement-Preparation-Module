# Write your MySQL query statement below
# select name from Customer where referee_id <> 2 or referee_id=null;
select name from Customer where id not in (select id from Customer where referee_id = 2);