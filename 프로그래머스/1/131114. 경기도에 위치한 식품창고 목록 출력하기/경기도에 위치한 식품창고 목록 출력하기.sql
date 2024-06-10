select warehouse_id, warehouse_name, address,
case when freezer_yn is null then 'N' else freezer_yn END FREEZER_YN
from food_warehouse
where address like '경기도%'
order by warehouse_id asc;