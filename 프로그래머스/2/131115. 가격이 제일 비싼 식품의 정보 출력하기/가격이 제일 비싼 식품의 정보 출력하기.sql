select product_id, product_name, product_cd, category, price
from food_product
where price in (select max(price) from food_product);