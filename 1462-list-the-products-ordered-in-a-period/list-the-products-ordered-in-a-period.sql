# Write your MySQL query statement below
select product_name,sum(unit) as unit from Products
left join Orders
on Products.product_id=Orders.product_id
where substr(order_date,1,7)='2020-02' 
group by Products.product_id
having unit>=100