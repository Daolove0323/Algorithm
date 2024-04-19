SELECT CONCAT('/home/grep/src/', a.board_id, '/', b.FILE_ID, b.file_name, b.file_ext) file_path
FROM used_goods_board a JOIN used_goods_file b ON a.board_id=b.board_id
WHERE views = (SELECT max(views) FROM used_goods_board)
ORDER BY file_id desc