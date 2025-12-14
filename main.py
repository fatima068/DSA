def format_num(x):
    if abs(x - round(x)) < 1e-9:
        return str(int(round(x)))
    else:
        return f"{x:.4f}"


def print_matrix(mat, msg=None):
    if msg:
        print("\n" + msg)
    for row in mat:
        print("  ".join(f"{format_num(x):>8}" for x in row))
    print()


def gauss_jordan(a):
    rows = len(a)
    cols = len(a[0])
    n = rows

    row = 0
    for col in range(cols - 1):
        pivot = row
        while pivot < n and abs(a[pivot][col]) < 1e-9:
            pivot += 1

        if pivot == n:
            continue

        if pivot != row:
            a[row], a[pivot] = a[pivot], a[row]
            print_matrix(a, f"Swapped row {row} with row {pivot}")

        pivot_val = a[row][col]
        if abs(pivot_val) > 1e-9:
            a[row] = [x / pivot_val for x in a[row]]
            print_matrix(a, f"Divided row {row} by pivot {format_num(pivot_val)}")

        for r in range(n):
            if r != row and abs(a[r][col]) > 1e-9:
                factor = a[r][col]
                a[r] = [a[r][i] - factor * a[row][i] for i in range(cols)]
                print_matrix(a, f"R{r} = R{r} - ({format_num(factor)}) * R{row}")

        row += 1

    return a


def gauss_elimination(a):
    n = len(a)
    m = len(a[0])

    for col in range(n):

        pivot = col
        while pivot < n and abs(a[pivot][col]) < 1e-9:
            pivot += 1

        if pivot == n:
            continue

        if pivot != col:
            a[col], a[pivot] = a[pivot], a[col]
            print_matrix(a, f"Swapped row {col} with row {pivot}")

        for r in range(col + 1, n):
            if abs(a[r][col]) > 1e-9:
                factor = a[r][col] / a[col][col]
                a[r] = [a[r][i] - factor * a[col][i] for i in range(m)]
                print_matrix(a, f"R{r} = R{r} - ({format_num(factor)}) * R{col}")

    print_matrix(a, "Upper Triangular Matrix:")

    for r in range(n):
        if all(abs(x) < 1e-9 for x in a[r][:-1]) and abs(a[r][-1]) > 1e-9:
            return a, "no_solution", None

    x = [0] * n

    for i in range(n - 1, -1, -1):
        if abs(a[i][i]) < 1e-9:
            return a, "infinite", None

        s = a[i][-1]
        for j in range(i + 1, n):
            s -= a[i][j] * x[j]
        x[i] = s / a[i][i]

    return a, "unique", x

def extract_infinite_from_ref(mat):
    n = len(mat)
    m = len(mat[0])
    num_vars = m - 1

    leading = [-1] * n
    for r in range(n):
        for c in range(num_vars):
            if abs(mat[r][c]) > 1e-9:
                leading[r] = c
                break

    free_vars = [v for v in range(num_vars) if v not in leading]

    solutions = {}
    for r in range(n):
        if leading[r] != -1:
            var = leading[r]
            const = mat[r][-1]
            eq = {}

            for c in range(var + 1, num_vars):
                if abs(mat[r][c]) > 1e-9:
                    eq[c] = -mat[r][c] / mat[r][var]

            const = const / mat[r][var]
            solutions[var] = (eq, const)

    return solutions, free_vars


def analyze_solution(mat):
    rows = len(mat)
    cols = len(mat[0])
    num_vars = cols - 1

    for r in mat:
        if all(abs(x) < 1e-9 for x in r[:-1]) and abs(r[-1]) > 1e-9:
            return "no_solution"

    pivots = 0
    for r in mat:
        if any(abs(x) > 1e-9 for x in r[:-1]):
            pivots += 1

    if pivots < num_vars:
        return "infinite"

    return "unique"


def extract_unique(mat):
    return [row[-1] for row in mat]


def extract_infinite(mat):
    cols = len(mat[0])
    num_vars = cols - 1

    leading = [-1] * len(mat)
    for r in range(len(mat)):
        for c in range(num_vars):
            if abs(mat[r][c]) > 1e-9:
                leading[r] = c
                break

    free_vars = [v for v in range(num_vars) if v not in leading]

    solutions = {}
    for r in range(len(mat)):
        if leading[r] != -1:
            var = leading[r]
            eq = {var: 1}
            const = mat[r][-1]
            for c in range(leading[r] + 1, num_vars):
                if abs(mat[r][c]) > 1e-9:
                    eq[c] = -mat[r][c]
            solutions[var] = (eq, const)

    return solutions, free_vars



def main():
    print("\n--- Linear System Solver ---")
    print("1. Gauss Jordan Elimination")
    print("2. Gauss Elimination")

    method = int(input("Choose method (1 or 2): "))

    n = int(input("\nEnter number of equations: "))

    print("\nEnter augmented matrix (each row):")
    a = []
    for i in range(n):
        row = list(map(float, input(f"Row {i+1}: ").split()))
        a.append(row)

    print_matrix(a, "\nInitial Matrix:")

    if method == 2:

        final, sol_type, sol = gauss_elimination(a)

        if sol_type == "unique":
            print("\n→ UNIQUE SOLUTION:")
            for i, val in enumerate(sol):
                print(f"  x{i+1} = {format_num(val)}")

        elif sol_type == "no_solution":
            print("\n→ NO SOLUTION (Inconsistent).")

        else:
            print("\n→ INFINITE SOLUTIONS (Parameterized form):")

            solutions, free_vars = extract_infinite_from_ref(final)

            print("\nFree variables:")
            for v in free_vars:
                print(f"  x{v+1} = t{v+1}")

            print("\nSolution:")
            for var, (eq, const) in solutions.items():
                line = f"x{var+1} = {format_num(const)}"
                for fv, coeff in eq.items():
                    line += f" + ({format_num(coeff)})*t{fv+1}"
                print("  " + line)

    else:
        final = gauss_jordan(a)
        print_matrix(final, "Final Reduced Matrix (RREF):")

        sol_type = analyze_solution(final)

        if sol_type == "unique":
            sol = extract_unique(final)
            print("→ UNIQUE SOLUTION:")
            for i, x in enumerate(sol):
                print(f"  x{i+1} = {format_num(x)}")

        elif sol_type == "no_solution":
            print("→ NO SOLUTION (Inconsistent).")

        else:
            print("→ INFINITE SOLUTIONS:")

            solutions, free_vars = extract_infinite(final)

            print("\nFree variables:")
            for v in free_vars:
                print(f"  x{v+1} is free (t{v+1})")

            print("\nSolution (parameter form):")
            for var, (eq, const) in solutions.items():
                equation = f"x{var+1} = {format_num(const)}"
                for other, coeff in eq.items():
                    if other != var:
                        equation += f" + ({format_num(coeff)})*t{other+1}"
                print("  " + equation)

            for v in free_vars:
                print(f"  x{v+1} = t{v+1}")


if __name__ == "__main__":
    main()