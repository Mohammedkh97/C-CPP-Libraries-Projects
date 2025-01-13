The key reason your code compiles successfully when using Bash (via `MSYS2`) but fails in other environments (like `cmd` or similar) lies in **how the development environment is set up**. Bash under MSYS2 provides a properly configured environment for building GTK applications, including access to `pkg-config`, correct paths, and other dependencies. Here’s why:

---

### 1. **Environment Variables**
   - When you use `MSYS2 Bash`, it sets up environment variables like `PATH`, `PKG_CONFIG_PATH`, and other important configurations.
   - These variables ensure:
     - `gcc` can find the GTK+ headers (`-I` include paths).
     - `ld` (the linker) can find the libraries (`-L` library paths).
     - `pkg-config` works correctly to supply the necessary flags for GTK compilation.

   **Example Environment Variables in MSYS2 Bash:**
   - `PATH` includes `/mingw64/bin` (where GTK libraries and tools like `pkg-config` reside).
   - `PKG_CONFIG_PATH` includes `/mingw64/lib/pkgconfig` (where `.pc` files for GTK are located).

   When using `cmd` or other shells, these paths may not be set unless explicitly configured.

---

### 2. **`pkg-config` Availability**
   - In MSYS2 Bash, `pkg-config` is readily available and functional, ensuring it supplies the correct flags for GTK compilation (`--cflags` and `--libs`).
   - Outside MSYS2, `pkg-config` may not be installed or may fail to find the GTK `.pc` files, leading to errors about missing headers or libraries.

---

### 3. **Filesystem Mapping**
   - MSYS2 Bash properly maps paths to the POSIX-style paths expected by `pkg-config` and GCC (e.g., `/mingw64/include/gtk-3.0`).
   - `cmd` or other shells may require manual translation of these paths to Windows-style paths (e.g., `C:\msys64\mingw64\include\gtk-3.0`).

---

### 4. **MinGW Toolchain Integration**
   - The MinGW toolchain (GCC, linker, etc.) is tightly integrated into the MSYS2 Bash environment.
   - Outside MSYS2, you must manually specify paths to the MinGW GCC executable and related tools.

---

### Why Bash Works Well for GTK Development
The MSYS2 Bash environment is designed specifically to support building applications that rely on Unix-like tools (like GTK+). It provides:
- A consistent toolchain.
- All dependencies and libraries in one place.
- Automatic path and configuration management.

When you use Bash, these complexities are handled for you. When using `cmd` or other shells, you must manually replicate this setup.

---

### Solution for Non-Bash Environments
If you need to compile in `cmd` or another environment, replicate the MSYS2 Bash setup:
1. **Add MinGW paths to `PATH`:**
   ```cmd
   set PATH=C:\msys64\mingw64\bin;C:\msys64\mingw64\include;%PATH%
   ```

2. **Set `PKG_CONFIG_PATH`:**
   ```cmd
   set PKG_CONFIG_PATH=C:\msys64\mingw64\lib\pkgconfig
   ```

3. **Use Full Paths for Include and Libraries (if needed):**
   ```cmd
   gcc test_gtk.c -o test_gtk ^
   -IC:\msys64\mingw64\include\gtk-3.0 ^
   -IC:\msys64\mingw64\include\glib-2.0 ^
   -LC:\msys64\mingw64\lib ^
   -lgtk-3 -lgdk-3 -lgobject-2.0 -lglib-2.0 -lintl
   ```

---

### Recommendation
For GTK+ development on Windows, it's best to stay within the MSYS2 Bash environment to avoid these setup issues. It's simpler, faster, and avoids manual configuration errors.