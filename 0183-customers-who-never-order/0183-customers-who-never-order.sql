# Write your MySQL query statement below
SELECT NAME AS CUSTOMERS 
FROM CUSTOMERS 
WHERE ID NOT IN (SELECT CUSTOMERID FROM ORDERS);