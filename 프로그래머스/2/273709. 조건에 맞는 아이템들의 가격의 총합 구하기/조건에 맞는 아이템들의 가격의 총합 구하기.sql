select sum(price) total_price
from item_info
group by rarity
having rarity = 'legend';