select book_id, author_name, date_format(published_date, '%Y-%m-%d') published_date
from book a join author b on a.author_id = b.author_id
where category = '경제'
order by published_date;