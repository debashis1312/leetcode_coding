# Write your MySQL query statement below
select product_name,s.year,s.price
from sales s #s = elus
join product p on p.product_id=s.product_id
