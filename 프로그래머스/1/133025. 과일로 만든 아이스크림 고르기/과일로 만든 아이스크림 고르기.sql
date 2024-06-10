select a.flavor
from first_half a join icecream_info b on a.flavor=b.flavor
where total_order>=3000 and a.flavor in ('strawberry', 'melon')
order by total_order desc;