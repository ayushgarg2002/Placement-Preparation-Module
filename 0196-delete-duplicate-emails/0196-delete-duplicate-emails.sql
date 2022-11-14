# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below
# delete from person where id not in (select Min(id) from person group by email);
# delete A from Person A, Person B where A.id > B.id and A.email=B.email;

delete A FROM PERSON A, PERSON B WHERE A.EMAIL=B.EMAIL AND A.ID>B.ID;