select count(*) fish_count
from fish_info fi join fish_name_info fn on fi.fish_type=fn.fish_type
where fish_name in ('bass', 'snapper');