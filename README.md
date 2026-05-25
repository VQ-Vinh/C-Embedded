# Luyện tập C Embedded

Quá trình ôn luyện và thực hành các kỹ thuật C cốt lõi trong lập trình nhúng (firmware, bare-metal, RTOS).

## Cách chạy

```bash
make <tên_file>
# VD: make test, make Pointer/func_pointer
```

## Nội dung

### 1. Bitwise Operations — Thao tác bit cơ bản

Thao tác trên từng bit như set, clear, toggle, check — mô phỏng thao tác với thanh ghi phần cứng.

- `set_bit`, `clear_bit`, `toggle_bit`, `check_bit` — dùng `|=`, `&= ~`, `^=`, `&`
- `bit_modify` — mặt nạ + dịch bit để chỉnh sửa trường bit
- `decode_status_reg` — giải mã thanh ghi trạng thái
- `marco_based` — dùng macro để đóng gói bitfield
- `bit_set_range`, `keep_highest_set_bit`, `spreading_bit`

### 2. Bit Field Operation — Trích xuất & chỉnh sửa bitfield

Trích xuất và ghi đè một trường bit có độ dài bất kỳ trong thanh ghi.

- `extract_BitField` — `(reg >> pos) & ((1 << len) - 1)`
- `set_multiple_bits` — set đồng thời nhiều bit
- `extract_and_modify_field` — read-modify-write
- `extract_nibble`, `extract_even_bits`
- `data_trans` — dịch chuyển dữ liệu dạng bitfield

### 3. Bitwise Rotation and Counting — Xoay vòng & đếm bit

Kỹ thuật xoay bit và đếm bit, ứng dụng trong mã hóa, kiểm tra lỗi.

- `rotate_left` — xoay trái vòng: `(n << shift) | (n >> (width - shift))`
- `count_set_bits` — đếm bit 1 (popcount)
- `bit_reversal` — đảo thứ tự bit
- `check_power_of_two` — kiểm tra lũy thừa của 2: `n & (n-1)`
- `detect_circular` — phát hiện xoay vòng
- `compress_interleaved_bits` — nén bit xen kẽ

### 4. Array Manipulation — Xử lý mảng & buffer

Thao tác trên mảng, buffer dữ liệu nối tiếp (serialization).

- `reverse_array`, `left_rotate` — đảo/xoay mảng tại chỗ
- `sliding_window_sum` — cửa sổ trượt
- `find_duplicate` — tìm phần tử trùng
- `checksum_validation` — tính checksum XOR
- `serialized_data_buffer` — đóng gói dữ liệu vào byte buffer (little-endian) như gửi qua UART/SPI

### 5. Pointer — Con trỏ & hàm

Con trỏ, con trỏ hàm, và kỹ thuật dispatch.

- `swap_value` — pass-by-reference
- `reverse_array`, `sum_even`, `find_maximum` — duyệt mảng bằng con trỏ
- `double_pointer` — con trỏ cấp 2
- `void_pointer` — con trỏ void
- `func_pointer`, `func_pointer_p2` — dispatch table dùng mảng con trỏ hàm, thay thế switch-case

## Yêu cầu

- GCC (MinGW/MSYS2)
- GNU Make
