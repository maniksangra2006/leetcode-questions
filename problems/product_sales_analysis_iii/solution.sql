# Write your MySQL query statement below
select s1.product_id as product_id,
s1.year as first_year,
s1.quantity as quantity,
s1.price as price
from sales s1 
inner join(
    select product_id,min(year) as early_year
    from sales group by product_id
) t
on t.product_id=s1.product_id
and s1.year=t.early_year;