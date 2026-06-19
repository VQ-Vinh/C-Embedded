# Luyện tập C Embedded

Quá trình ôn luyện và thực hành các kỹ thuật C cốt lõi trong lập trình nhúng (firmware, bare-metal, RTOS).

## Cách chạy

```bash
make <tên_file>
# VD: make test, make "01. Bitwise Operations/01_bit_modify"
# Hoặc cd vào thư mục con rồi chạy:
cd "01. Bitwise Operations"
make 01_bit_modify
```

## Nội dung

### 01. Bitwise Operations — Thao tác bit cơ bản

Thao tác trên từng bit như set, clear, toggle, check — mô phỏng thao tác với thanh ghi phần cứng.

| File | Kỹ thuật |
|------|----------|
| `01_bit_modify` | Dùng mask + dịch bit để set/clear một field trong thanh ghi: `(reg & ~mask) \| (val << pos)` |
| `02_bit_toggle` | Đảo bit dùng `^=` |
| `03_check_bit` | Kiểm tra bit dùng `&` |
| `04_set_bit` | Set bit dùng `\|=` |
| `05_clear_bit` | Clear bit dùng `&=` và `~` |
| `08_bit_set_range` | Set tất cả bit trong một khoảng [L, R] |
| `09_keep_highest_set_bit` | Giữ lại bit cao nhất đang bật, tắt hết bit còn lại |
| `10_bit_operations` | Tổng hợp các thao tác bit cơ bản |
| `11_decode_status_reg` | Giải mã thanh ghi trạng thái từ nhiều flag bits |
| `12_spreading_bit` | Trải bit — nhân bản bit sang vị trí khác |
| `13_marco_based` | Dùng macro `SET_BIT/CLR_BIT/GET_BIT` để đóng gói bitfield |

### 02. Bit Field Operation — Trích xuất & chỉnh sửa bitfield

Trích xuất và ghi đè một trường bit có độ dài bất kỳ trong thanh ghi.

| File | Kỹ thuật |
|------|----------|
| `17_extract_nibble` | Trích nibble (4 bit) từ số nguyên |
| `18_set_multiple_bits` | Set đồng thời nhiều bit bằng mask tổng hợp |
| `19_extract_BitField` | `(reg >> pos) & ((1 << len) - 1)` — trích field độ dài bất kỳ |
| `22_extract_even_bits` | Lấy các bit ở vị trí chẵn, ghép lại thành số mới |
| `24_data_trans` | Dịch chuyển dữ liệu dạng bitfield giữa các thanh ghi |
| `26_extract_and_modify_field` | Read-modify-write: đọc, sửa field, ghi lại |

### 03. Bitwise Rotation and Counting — Xoay vòng & đếm bit

Kỹ thuật xoay bit và đếm bit, ứng dụng trong mã hóa, kiểm tra lỗi, checksum.

| File | Kỹ thuật |
|------|----------|
| `30_count_set_bits` | Đếm bit 1 (popcount) — dùng vòng lặp hoặc `n & (n-1)` |
| `31_rotate_left` | Xoay trái vòng: `(n << shift) \| (n >> (width - shift))` |
| `33_detect_circular` | Phát hiện số có thể xoay vòng thành nhau |
| `35_check_power_of_two` | Kiểm tra lũy thừa của 2: `n & (n-1) == 0` |
| `36_bit_reversal` | Đảo thứ tự bit (mirror) — dùng vòng lặp hoặc lookup table |
| `37_compress_interleaved_bits` | Nén bit xen kẽ (interleaving) — dùng trong mã hóa |

### 04. Array Manipulation — Xử lý mảng & buffer

Thao tác trên mảng, buffer dữ liệu nối tiếp (serialization).

| File | Kỹ thuật |
|------|----------|
| `40_checksum_validation` | Tính và kiểm tra checksum XOR trên mảng byte |
| `41_reverse_array` | Đảo ngược mảng tại chỗ — dùng hai con trỏ đầu-cuối |
| `42_left_rotate` | Xoay mảng trái k vị trí — dùng reverse từng đoạn |
| `43_find_duplicate` | Tìm phần tử trùng trong mảng — dùng flag array |
| `44_sliding_window_sum` | Cửa sổ trượt — tính tổng dãy con liên tiếp |
| `45_serialized_data_buffer` | Đóng gói dữ liệu nhiều kiểu vào byte buffer (little-endian) mô phỏng UART/SPI |

### 05. Pointer — Con trỏ & hàm

Con trỏ, con trỏ hàm, dispatch table, ép kiểu — kỹ thuật nền tảng trong C nhúng.

| File | Kỹ thuật |
|------|----------|
| `48_swap_value` | Pass-by-reference dùng con trỏ |
| `49_sum_even` | Duyệt mảng bằng con trỏ, tính tổng số chẵn |
| `50_reverse_array` | Đảo mảng bằng con trỏ đầu-cuối |
| `51_find_maximum` | Tìm max bằng con trỏ |
| `53_double_pointer` | Con trỏ cấp 2 — cấp phát và thay đổi con trỏ trong hàm |
| `55_void_pointer` | Con trỏ void — xử lý dữ liệu đa kiểu |
| `56_func_pointer` | Con trỏ hàm cơ bản — gọi hàm qua con trỏ |
| `57_func_pointer_p2` | Dispatch table — mảng con trỏ hàm thay thế switch-case |
| `59_find_incr_val` | Dùng con trỏ dò tìm 3 số tăng dần liên tiếp |
| `60_detect_alternating_pattern` | Kiểm tra đoạn bộ nhớ có pattern 0xA – 0x5 xen kẽ không |
| `molding` | Ép kiểu con trỏ — đọc mảng `int` dưới dạng từng byte |

### 06. Union — Truy xuất dữ liệu kiểu union

Kỹ thuật dùng `union` để truy xuất cùng vùng nhớ dưới nhiều kiểu — ứng dụng giải mã thanh ghi, đóng gói packet, truyền float qua UART.

| File | Kỹ thuật |
|------|----------|
| `67_control_register` | Union lồng struct bitfield để thao tác thanh ghi điều khiển 32-bit |
| `68_union_extract_bytes` | Union `uint32_t` với mảng `uint8_t[4]` — đọc từng byte của số 32-bit |
| `69_modify_bytes` | Đọc/sửa byte cụ thể trong số 32-bit qua union |
| `70_packet_layout` | Union overlay nhiều cấu trúc packet — dùng `#pragma packed` |
| `71_decode_ADC_result` | Union giải mã kết quả ADC 12-bit kèm số kênh |
| `72_transmit_float` | Union gửi float dạng byte array qua UART |
| `quiz` | Câu đố về memory layout của union — kiểm tra alignment |

### 07. Structures — Cấu trúc & bitfield

Thao tác trên `struct`, bitfield, padding, và đóng gói dữ liệu — mô phỏng driver thiết bị nhúng.

| File | Kỹ thuật |
|------|----------|
| `75_pointer_to_struct` | Con trỏ tới struct bitfield mô phỏng thanh ghi UART |
| `76_construct_uart` | Xây dựng cấu hình UART (baud rate, stop bit, parity) từ bitfield |
| `77_validate_conf` | Kiểm tra bit hợp lệ trong struct thanh ghi cấu hình |
| `78_struct_padding` | Hiểu padding và sắp xếp lại trường để tối ưu bộ nhớ (đo `sizeof`) |
| `79_extract_packet_fields` | Ánh xạ packet bytes vào struct `#pragma packed` |
| `80_register_bitfields` | Bitfield struct mô phỏng thanh ghi 8-bit |
| `81_filter_structs` | Lọc mảng struct theo điều kiện (cảm biến > ngưỡng) |

### 08. Circular Buffer — Hàng đợi vòng

Triển khai cấu trúc hàng đợi vòng (circular buffer / ring buffer) — dùng trong xử lý dữ liệu UART, SPI, ADC.

| File | Kỹ thuật |
|------|----------|
| `85_insert` | Chèn dữ liệu vào circular buffer với head/tail pointer, kiểm tra full/empty |

### 09. Strings and Character Handling — Xử lý chuỗi

Tự triển khai lại các hàm thao tác chuỗi, chuyển đổi kiểu, và phân tích dữ liệu văn bản — kỹ năng quan trọng khi làm việc với giao thức truyền thông, GPS, AT command.

| File | Kỹ thuật |
|------|----------|
| `90_custom_strlen` | Tự viết `strlen` — đếm ký tự đến `\0` |
| `91_custom_strcpy` | Tự viết `strcpy` — copy chuỗi |
| `92_custom_strcmp` | Tự viết `strcmp` — so sánh hai chuỗi |
| `93_reverse_string` | Đảo ngược chuỗi tại chỗ |
| `94_remove_duplicate` | Xóa ký tự trùng trong chuỗi — thao tác tại chỗ |
| `95_cout_all` | Đếm tần suất xuất hiện từng ký tự trong chuỗi |
| `96_upper_to_lower` | Chuyển chuỗi in hoa sang in thường |
| `97_comma_separated` | Phân tích chuỗi phân cách bằng dấu phẩy (CSV) thành các token |
| `98_str_to_int` | Chuyển chuỗi số thành `int` — tự viết `atoi` |
| `100_str_to_float` | Chuyển chuỗi thành `float` — xử lý phần nguyên, phần thập phân, dấu âm |
| `101_split_str` | Tách chuỗi dùng delimiter — mô phỏng `strtok` |
| `102_parse_gps` | Phân tích chuỗi GPS NMEA ($GPGGA) — trích múi giờ, vĩ độ, kinh độ |

### 10. Searching and Sorting — Tìm kiếm & sắp xếp

Thuật toán cơ bản trên mảng — tìm kiếm tuyến tính, nhị phân, sắp xếp, chọn top K.

| File | Kỹ thuật |
|------|----------|
| `106_linear_search` | Tìm tuyến tính — trả về index phần tử đầu tiên |
| `107_binary_search` | Tìm nhị phân trên mảng đã sắp xếp — O(log n) |
| `109_sorting` | Sắp xếp nổi bọt (bubble sort) — O(n²) |
| `111_find_Kth_minmax` | Tìm phần tử nhỏ thứ k và lớn thứ k |
| `112_find_top3` | Tìm 3 giá trị lớn nhất trong mảng — quét một lượt |

## Yêu cầu

- GCC (MinGW/MSYS2)
- GNU Make
