select distinct user_id, product_id
from online_sale a
group by user_id, product_id
having count(*) >= 2
order by user_id, product_id desc