# 1436. Destination City


## Description

You are given the array `paths`, where `paths[i] = [cityAi, cityBi]` means there exists a direct path going from `cityAi` to `cityBi`.

Return the destination city, that is, the city without any outgoing path.

It is guaranteed that the graph of paths forms a line without any loop, therefore there will be exactly one destination city.

---

# Example 1

## Input

```text
paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
```

## Output

```text
"Sao Paulo"
```

## Explanation

Starting at `"London"` city you will reach `"Sao Paulo"` city which is the destination city. Your trip consist of:

```text
"London" -> "New York" -> "Lima" -> "Sao Paulo"
```

---

# Example 2

## Input

```text
paths = [["B","C"],["D","B"],["C","A"]]
```

## Output

```text
"A"
```

## Explanation

All possible trips are:

```text
"D" -> "B" -> "C" -> "A"
```

```text
"B" -> "C" -> "A"
```

```text
"C" -> "A"
```

`"A"` is the destination city because it has no outgoing path.

---

# Example 3

## Input

```text
paths = [["A","Z"]]
```

## Output

```text
"Z"
```

---

# Constraints

- `1 <= paths.length <= 100`
- `paths[i].length == 2`
- `1 <= cityAi.length, cityBi.length <= 10`
- `cityAi != cityBi`
- All strings consist of lowercase and uppercase English letters and the space character.