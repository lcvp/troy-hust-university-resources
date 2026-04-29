# Đóng Góp

>"A society grows great when old men plant trees in whose shade they know they shall never sit."  
— **Greek Proverb**

Xin chào, nếu bạn đang đọc file này thì khả năng là bạn đang muốn đóng góp thông tin cho repo! Cảm ơn bạn!  
File này sẽ trả lời một số câu hỏi thường gặp và hướng dẫn qua cách đóng góp cho repo.  
Nếu như bạn vẫn còn thắc mắc, bạn có thể mở một [issue][github-issue] trên repo này.  

## Tôi có thể đóng góp những gì?
- Bất kì những gì bạn nghĩ có thể giúp ích cho sinh viên hiện tại hoặc tương lai! Ví dụ như:
  - Tài liệu mới (đề thi 👀, slide, bài tập mẫu, ...)
  - Cập nhật thông tin môn học/giảng viên đã lỗi thời
  - Thêm thông tin còn thiếu
  - Sửa lỗi chính tả, format, cấu trúc của repo
  - ...

## Vậy cấu trúc của repo này như nào?
- Thư mục gốc (`Root`):
  - Chứa các thư mục riêng biệt cho từng môn học, được đặt tên chuẩn theo mã môn (ví dụ: `CS-3310`, `BIO-1100`, `ECO-2251`, ...)
  - `Faculty/`: Chứa thông tin về các giảng viên Troy (dưới dạng `Tên-Giảng-Viên.md`)
  - `CONTRIBUTING.md`: file này!
  - `README.md`: file tổng quan của repo
  - ...

- Bên trong thư mục của mỗi môn học (ví dụ: `ART-1133/`):
  - `Assignments/`: Chứa đề thi, bài tập, project, quiz, ...
  - `Modules/`: Chứa slide bài giảng
  - `References/`: Chứa sách giáo trình, tài liệu tham khảo bên ngoài, cheat sheet, ...
  - `Syllabi/`: Chứa các lộ trình môn học
  - `README.md`: Thông tin tổng quan của môn học (review môn học, danh sách giảng viên)

## Tôi có cần lưu ý điều gì khi đóng góp không?
Bọn mình biết bạn đang bỏ thời gian của mình ra để giúp cho các sinh viên khác mà không đòi hỏi gì, và bọn mình không muốn được voi đòi tiên.  
Vì vậy, những yêu cầu dưới đây phần lớn chỉ là gợi ý. Dữ liệu là dữ liêu, bạn vẫn nên mở pull request nếu bạn có dữ liệu tốt kể cả nếu bạn không follow đúng format 100%. Các người đóng góp khác có thể sửa lại cho đúng format giúp bạn sau.  
Những thứ nên làm:
- **Định dạng file:**
  - Đề thi: Ưu tiên `PDF` > `Markdown` > `Ảnh` > Các định dạng khác.
  - Slide bài giảng: Nếu đang ở dạng PowerPoint (`.ppt`, `.pptx`), bạn nên xuất ra `PDF` để mọi người có thể xem trực tiếp trên GitHub mà không cần tải về.
- **Quy tắc đặt tên:**
  - Để thống nhất, hãy đặt tên thư mục/file theo chuẩn Pascal-Kebab case (Viết hoa chữ cái đầu và nối nhau bằng dấu gạch ngang). 
  - *Ví dụ:* `Course-Descriptions`, `Final-Exams`, `Homework-Problems.pdf`...
- **Phân loại theo cấu trúc:**
  - Các tài liệu bên trong thư mục môn học nên được chia sâu hơn theo thứ tự: `.../Kỳ-học/Giảng-viên/Loại-tài-liệu/Mã-lớp/...`
  - *Ví dụ:* 1 file đề thi giữa kì môn MTH-2215 của thầy Vũ Thế Khôi, kì Spring 2026 sẽ có đường dẫn như sau:
  `MTH-2215/Assignments/Spring-2026/Vu-The-Khoi/Midterm/IHAA.pdf`

## Vậy làm thế nào để tôi đóng góp cho repo này?

### Cách 1: Sửa nhanh (Dành cho lỗi chính tả, chỉnh sửa ngắn, ...)
1. **Tìm file**: Truy cập vào file `.md` cần sửa trên giao diện GitHub.
2. **Chỉnh sửa**: Nhấn vào biểu tượng **cái bút** (**Edit this file**) ở góc trên bên phải.
3. **Sửa nội dung**: Tiến hành chỉnh sửa trực tiếp nội dung trong khung soạn thảo.
4. **Gửi yêu cầu**:
    * Kéo xuống phần **Commit changes**.
    * Ghi tiêu đề ngắn gọn (ví dụ: "[CS-3310] Improved formatting").
    * Chọn dòng **Create a new branch for this commit and start a pull request**.
    * Nhấn **Propose changes** -> **Create Pull Request**.

### Cách 2: Fork và sửa trên trình duyệt (Dành cho việc upload tài liệu)
1. **Fork**: Nhấn nút **Fork** (góc trên cùng bên phải) để tạo một bản sao của dự án về tài khoản cá nhân của bạn.
2. **Tải file lên**: 
    * Di chuyển vào đúng thư mục cần lưu theo cấu trúc dự án.
    * Nhấn nút **Add file** -> **Upload files**.
    * Kéo thả các file của bạn vào khung và chờ tải xong.
3. **Xác nhận**: Kéo xuống dưới cùng, nhấn **Commit changes**.
4. **Gửi Pull Request**:
    * Quay lại trang chủ của bản Fork (trong tài khoản của bạn).
    * Nhấn nút **Contribute** -> chọn **Open Pull Request** để gửi các thay đổi về dự án gốc.

### Cách 3: Clone về máy (Dễ hơn cho việc chỉnh sửa nhiều file một lúc)
1. **Chuẩn bị**: Tải và cài đặt [Git][git-install].
2. **Fork & Clone**:
    * Nhấn **Fork** dự án về tài khoản của bạn.
    * Tại bản Fork đó, nhấn nút **Code** (màu xanh) và sao chép đường dẫn (URL).
    * Mở Terminal (hoặc Command Prompt) và gõ lệnh:
      ```bash
      git clone <đường-dẫn-vừa-copy>
      ```
3. **Chỉnh sửa**: Mở thư mục vừa tải về và thực hiện thêm mới hoặc sửa đổi các file theo ý muốn.
4. **Đẩy dữ liệu lên GitHub**:
    * Mở Terminal (hoặc Command Prompt) tại thư mục dự án và chạy các lệnh:
      ```bash
      git add .
      git commit -m "Mô tả nội dung bạn đã thay đổi"
      git push
      ```
5. **Gửi yêu cầu**: Quay lại trang GitHub của dự án gốc. Bạn sẽ thấy thông báo màu vàng **"Compare & pull request"**. Nhấn vào đó, kiểm tra lại nội dung và xác nhận gửi.


[github-issue]: ../../issues
[git-install]: https://git-scm.com/install/
