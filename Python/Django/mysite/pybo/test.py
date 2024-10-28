def process_order_list(db_function, status_message, success_message, sticker_id):
    order_no_list = [order_no[0] for order_no in db_function(conn)]
    if order_no_list:
        for i in range(0, len(order_no_list), chunk_size):
            chunk = ', '.join(map(str, order_no_list[i:i + chunk_size]))
            bot.send_bot_message_and_write_log('INFO', chunk + '\n')
            bot.send_bot_message_to_crm('text', chunk + '\n')

        bot.send_bot_message_and_write_log("INFO", f"\n{status_message}")
        bot.send_bot_message_to_crm('text', success_message)
        bot.send_bot_message_to_crm('sticker', '스티커', 446, sticker_id)


chunk_size = 80

# 직권처리 자동화 성공 주문번호 알람
process_order_list(
    db.select_automation_success_order_nos,
    "직권처리 자동화 성공 주문번호",
    "구매결정 직권처리 성공했어요~",
    1993
)

# 직권처리 자동화 실패 주문번호 알람
process_order_list(
    db.select_automation_fail_order_nos,
    "직권처리 자동화 실패 주문번호",
    "\n\n 도와주세요~ 자동화 처리에 실패했어요ㅠㅠ",
    2018
)

# 직권처리 자동화 기처리 주문번호 알람 및 확인 요청
process_order_list(
    db.select_preprocessed_order_nos,
    "직권처리 기처리 주문번호",
    "\n\n 얘네들은 누가 먼저 직권처리를 했네요???;; 그래두 한번 확인부탁드려요~",
    2015
)

# 직권처리 자동화 불가 주문번호 알람
process_order_list(
    db.select_manual_processing_required_order_nos,
    "직권처리 자동화 불가 주문번호",
    "\n\n 얘네들 혼구녕 좀 내줘유~ 구매결정 하란지가 언젠데!!!!",
    2019
)
