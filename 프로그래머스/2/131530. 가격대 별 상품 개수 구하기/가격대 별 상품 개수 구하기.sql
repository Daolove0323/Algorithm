select truncate(price, -4) price_group, count(*) products
from product
group by truncate(price, -4)
order by price_group;