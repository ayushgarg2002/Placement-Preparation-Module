# Write your MySQL query statement below
# UPDATE NAME FROM USERS 
SELECT USER_ID, CONCAT(UCASE(SUBSTR(NAME,1,1)), LCASE(SUBSTR(NAME,2))) AS name FROM USERS
order by user_id;
