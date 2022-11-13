# Write your MySQL query statement below
# SELECT employee_id , SALARY AS BONUS FROM EMPLOYEES WHERE MOD(EMPLOYEE_ID, 2)!=0 AND NAME NOT LIKE 'm%'ELSE SELECT EMPLOYEE_ID , 0 FROM EMPLOYEES ; 
SELECT EMPLOYEE_ID, IF(MOD(EMPLOYEE_ID, 2)!=0 AND NAME NOT LIKE 'm%', SALARY, 0) AS BONUS FROM EMPLOYEES ORDER BY EMPLOYEE_ID ;
