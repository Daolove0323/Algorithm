select distinct user_id, product_id
from online_sale a
where (product_id) in (select product_id
                     from online_sale b
                     where a.user_id=b.user_id
                     group by product_id
                     having count(*) >= 2
                      )
order by user_id, product_id desc