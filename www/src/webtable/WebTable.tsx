import { WebTablePlugin } from "./WebTablePlugin";

import "./WebTable.css";
import { useContext, useState } from "react";
import { WebTableContext } from "./WebTableContext";

interface Props<Item> {
  dataSource: Array<Item>;
  columns: Array<{
    cell: (item: Item) => React.ReactNode;
    key: string;
    label: string;
  }>;
  getUniqueID: (item: Item) => string;
  pagination?: string;
  enableSelection?: boolean;
  // plugins?: typeof WebTablePlugin<Item>;
  /**
   * plugins={{
   *  customRender,
   *  expansion,
   *  rowHeader,
   *  selection,
   * }}
   */
}

export function WebTable<T>(props: Props<T>): React.ReactElement {
  const [selectedRows, setSelectedRows] = useState<Map<string, boolean>>(
    new Map<string, boolean>()
  );
  console.log("selectedRows", selectedRows);
  return (
    <WebTableContext.Provider
      value={{
        selectedRows,
        onSelectRow: null,
        onUnselectRow: null,
      }}
    >
      <WebTableInternal {...props} />
    </WebTableContext.Provider>
  );
}

export function WebTableInternal<T>({
  dataSource: rows,
  columns,
  getUniqueID,
  enableSelection,
}: Props<T>): React.ReactElement {
  const { onSelectRow, onUnselectRow } = useContext(WebTableContext);
  return (
    <table>
      <thead>
        <tr>
          {columns.map((col, index) => (
            <td key={col.key}>{col.label}</td>
          ))}
        </tr>
      </thead>
      <tbody>
        {rows.map((row: T) => {
          return (
            <tr key={getUniqueID(row)}>
              {columns.map((col, index) => {
                if (enableSelection === true && index === 0) {
                  return (
                    <WebTableStatefulTD key={col.key} selectable>
                      {col.cell(row)}
                    </WebTableStatefulTD>
                  );
                }
                return <td key={col.key}>{col.cell(row)}</td>;
              })}
            </tr>
          );
        })}
      </tbody>
    </table>
  );
}

function WebTableStatefulTD({
  children,
  selectable,
  onChecked,
}: {
  children: React.ReactNode;
  selectable: boolean;
  onChecked?: (checked: boolean) => void;
}) {
  const [checked, setChecked] = useState<boolean>(false);
  const handleChange = (evt: React.ChangeEvent<HTMLInputElement>) => {
    setChecked(evt.target.checked);
    if (onChecked != null) {
      onChecked(evt.target.checked);
    }
  };
  return (
    <td>
      {selectable && (
        <input
          type="checkbox"
          checked={checked}
          onChange={(evt) => setChecked(evt.target.checked)}
        />
      )}
      {children}
    </td>
  );
}
